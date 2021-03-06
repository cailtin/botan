/*
* SHAKE-128
* (C) 2016 Jack Lloyd
*
* Botan is released under the Simplified BSD License (see license.txt)
*/

#include <botan/shake_cipher.h>
#include <botan/exceptn.h>
#include <botan/sha3.h>
#include <botan/loadstor.h>

namespace Botan {

SHAKE_128_Cipher::SHAKE_128_Cipher() :
   m_buf_pos(0)
   {}

void SHAKE_128_Cipher::cipher(const uint8_t in[], uint8_t out[], size_t length)
   {
   verify_key_set(m_state.empty() == false);

   while(length >= m_buffer.size() - m_buf_pos)
      {
      xor_buf(out, in, &m_buffer[m_buf_pos], m_buffer.size() - m_buf_pos);
      length -= (m_buffer.size() - m_buf_pos);
      in += (m_buffer.size() - m_buf_pos);
      out += (m_buffer.size() - m_buf_pos);

      SHA_3::permute(m_state.data());
      copy_out_le(m_buffer.data(), m_buffer.size(), m_state.data());

      m_buf_pos = 0;
      }
   xor_buf(out, in, &m_buffer[m_buf_pos], length);
   m_buf_pos += length;
   }

void SHAKE_128_Cipher::key_schedule(const uint8_t key[], size_t length)
   {
   m_state.resize(25);
   m_buffer.resize((1600 - 256) / 8);
   zeroise(m_state);

   for(size_t i = 0; i < length/8; ++i)
      {
      m_state[i] ^= load_le<uint64_t>(key, i);
      }

   m_state[length/8] ^= 0x000000000000001F;
   m_state[20]       ^= 0x8000000000000000;

   SHA_3::permute(m_state.data());
   copy_out_le(m_buffer.data(), m_buffer.size(), m_state.data());
   }

void SHAKE_128_Cipher::clear()
   {
   zap(m_state);
   zap(m_buffer);
   m_buf_pos = 0;
   }

void SHAKE_128_Cipher::set_iv(const uint8_t[], size_t length)
   {
   /*
   * This could be supported in some way (say, by treating iv as
   * a prefix or suffix of the key).
   */
   if(length != 0)
      throw Invalid_IV_Length(name(), length);
   }

void SHAKE_128_Cipher::seek(uint64_t)
   {
   throw Not_Implemented("SHAKE_128_Cipher::seek");
   }

Key_Length_Specification SHAKE_128_Cipher::key_spec() const
   {
   /*
   In principle SHAKE can accept arbitrary length inputs, but this
   does not seem required for a stream cipher.
   */
   return Key_Length_Specification(16, 160, 8);
   }

std::string SHAKE_128_Cipher::name() const
   {
   return "SHAKE-128";
   }

StreamCipher* SHAKE_128_Cipher::clone() const
   {
   return new SHAKE_128_Cipher;
   }

}
