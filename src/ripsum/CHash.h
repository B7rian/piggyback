//
// Copyright 2022 Brian W. Hughes
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#pragma once
#include <cstdint>
#include <string>
#include <openssl/evp.h>

class CHash {
	public:
		void InitHash(void);
		void AddBytesToHash2(uint8_t *aBytes, uint32_t aCount);
		void FinishHash(void);
		std::string GetChecksum(void) { return mChecksum; }
		void SetExpectedChecksum(std::string& aChecksum) {
			mExpectedChecksum = aChecksum;
		}
		bool ChecksumIsOk(void) { return mChecksum == mExpectedChecksum; }

	private:
		EVP_MD_CTX *mCtx;
		const EVP_MD *mMd;
		unsigned char mOutDigest[EVP_MAX_MD_SIZE];
		unsigned int mDigestLen;
		std::string mChecksum;
		std::string mExpectedChecksum;
};

