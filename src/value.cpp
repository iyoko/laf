/* Copyright 2013 Little IO
 *
 * laf is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * laf is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with laf.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "value.h"

namespace laf {

  Value::Value(laf_float value) : Processor(kNumInputs, 1), value_(value) {
    for (int i = 0; i < BUFFER_SIZE; ++i)
      outputs_[0]->buffer[i] = value_;
  }

  void Value::process() {
    if (outputs_[0]->buffer[0] == value_ &&
        outputs_[0]->buffer[BUFFER_SIZE - 1] == value_ &&
        !inputs_[kSet]->source->triggered) {
      return;
    }

    int i = 0;
    if (inputs_[kSet]->source->triggered) {
      int trigger_offset = inputs_[kSet]->source->trigger_offset;

      for (; i < trigger_offset; ++i)
        outputs_[0]->buffer[i] = value_;

      value_ = inputs_[kSet]->source->trigger_value;
    }

    for (; i < BUFFER_SIZE; ++i)
      outputs_[0]->buffer[i] = value_;
  }

  void Value::set(laf_float value) {
    value_ = value;
    for (int i = 0; i < BUFFER_SIZE; ++i)
      outputs_[0]->buffer[i] = value_;
  }
} // namespace laf
