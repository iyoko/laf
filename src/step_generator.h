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

#pragma once
#ifndef STEP_GENERATOR_H
#define STEP_GENERATOR_H

#include "processor.h"

#define DEFAULT_MAX_STEPS 128

namespace laf {

  class StepGenerator : public Processor {
    public:
      enum Inputs {
        kFrequency,
        kNumSteps,
        kReset,
        kSteps,
        kNumInputs
      };

      StepGenerator(int max_steps = DEFAULT_MAX_STEPS);

      virtual Processor* clone() const { return new StepGenerator(*this); }

      void process();

    protected:
      laf_float offset_;
      unsigned int current_step_;
  };
} // namespace laf

#endif // STEP_GENERATOR_H
