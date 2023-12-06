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

#include "absl/flags/commandlineflag.h"

#include <string>

#include "absl/base/config.h"
#include "absl/flags/internal/commandlineflag.h"
#include "absl/strings/string_view.h"

//ABSL_FLAG(std::string, string_flag, "dflt", "string_flag help");

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	absl::string_view s = absl::string_view((const char *)data, size);	
	std::string error;
	absl::CommandLineFlag clf;
	clf.ParseFrom(s, &error);

	return 0;
}
