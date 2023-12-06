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

#include "absl/base/attributes.h"
#include "absl/base/config.h"
#include "absl/base/log_severity.h"
#include "absl/log/internal/log_format.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_split.h"
#include "absl/strings/string_view.h"
#include "absl/time/civil_time.h"
#include "absl/time/time.h"
#include "absl/types/span.h"

const absl::TimeZone tz = absl::LocalTimeZone();

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {

	absl::Time timestamp;
	std::string time_err;

	const absl::string_view s = absl::string_view((const char *)data, size);	

	absl::ParseTime("%Y-%m-%d%ET%H:%M:%E*S", s,
                        tz, &timestamp, &time_err);

	return 0;
}
