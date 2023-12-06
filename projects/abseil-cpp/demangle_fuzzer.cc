// Copyright 2022 Google Inc.
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
////////////////////////////////////////////////////////////////////////////////

#include "absl/debugging/internal/demangle.h"

#include <string> 

#include "absl/base/config.h"
#include "absl/base/internal/raw_logging.h"
#include "absl/debugging/internal/stack_consumption.h"
#include "absl/memory/memory.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	static const int kOutSize = 1048576;
	auto out = absl::make_unique<char[]>(kOutSize);
	absl::debugging_internal::Demangle((const char *)data, out.get(), kOutSize);

	return 0;
}