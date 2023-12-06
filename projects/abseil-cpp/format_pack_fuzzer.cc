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

#include "absl/strings/internal/str_format/parser.h"
#include "absl/types/span.h"
#include "absl/strings/internal/str_format/arg.h"
#include "absl/strings/internal/str_format/bind.h"
#include "absl/strings/string_view.h"

#include <string.h>

#include "absl/base/macros.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  static int x = 0;
  const int *xp = &x;
  char c = 'h';
  char *mcp = &c;
  const char *cp = "hi";
  const char *cnil = nullptr;
  const int *inil = nullptr;
  using VoidF = void (*)();
  VoidF fp = [] {}, fnil = nullptr;
  volatile char vc;
  volatile char *vcp = &vc;
  volatile char *vcnil = nullptr;
  const absl::str_format_internal::FormatArgImpl args_array[] = {
      absl::str_format_internal::FormatArgImpl(xp),
	  absl::str_format_internal::FormatArgImpl(cp),
	  absl::str_format_internal::FormatArgImpl(inil),
	  absl::str_format_internal::FormatArgImpl(cnil),
	  absl::str_format_internal::FormatArgImpl(mcp),
	  absl::str_format_internal::FormatArgImpl(fp),
      absl::str_format_internal::FormatArgImpl(fnil),
	  absl::str_format_internal::FormatArgImpl(vcp),
	  absl::str_format_internal::FormatArgImpl(vcnil),
  };
  auto args = absl::MakeConstSpan(args_array);

  absl::str_format_internal::FormatPack(absl::str_format_internal::UntypedFormatSpecImpl(absl::string_view((const char *)data, size)), args);

  //absl::ParseFormatString(format, absl::ParsedFormatConsumer(this))

  return 0;
}