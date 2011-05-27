// Copyright 2011 Google Inc.
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

#ifndef SYZYGY_RELINK_ORDER_RELINKER_H_
#define SYZYGY_RELINK_ORDER_RELINKER_H_

#include "syzygy/relink/relinker.h"

class OrderRelinker : public Relinker {
 public:
  // Default constructor.
  OrderRelinker();

  // Sets the ordering file to use when reordering sections.
  void set_order_file(const FilePath& order_file_path);

 private:
  DISALLOW_COPY_AND_ASSIGN(OrderRelinker);

  // Overrides for base class methods.
  bool SetupOrdering(Reorderer::Order& order);
  bool ReorderSection(size_t section_index,
                      const IMAGE_SECTION_HEADER& section,
                      const Reorderer::Order& order);

  // The JSON encoded file with the new ordering.
  FilePath order_file_path_;
};

#endif  // SYZYGY_RELINK_ORDER_RELINKER_H_
