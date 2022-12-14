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

#include "CTaskState.h"

void CTaskState::Init(void) {
	InitFile();
	InitHash();
}

void CTaskState::Finish(void) {
	FinishFile();
	FinishHash();
}

void CTaskState::AddBytesToHash(void) {
	AddBytesToHash2(GetBuf(), GetBufCount());
}

