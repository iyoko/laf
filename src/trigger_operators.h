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
#ifndef TRIGGER_OPERATORS_H
#define TRIGGER_OPERATORS_H

#include "processor.h"

namespace laf {

  class TriggerCombiner : public Processor {
    public:
      TriggerCombiner();

      virtual Processor* clone() const { return new TriggerCombiner(*this); }

      void process();
  };

  class LegatoFilter : public Processor {
    public:
      enum Inputs {
        kLegato,
        kTrigger,
        kNumInputs
      };

      enum Outputs {
        kRetrigger,
        kRemain,
        kNumOutputs
      };

      LegatoFilter();

      virtual Processor* clone() const { return new LegatoFilter(*this); }

      void process();

    private:
      laf_sample last_value_;
  };

  class PortamentoFilter : public Processor {
    public:
      enum Inputs {
        kPortamento,
        kTrigger,
        kNumInputs
      };

      enum State {
        kPortamentoOff,
        kPortamentoAuto,
        kPortamentoOn
      };

      PortamentoFilter();

      virtual Processor* clone() const { return new PortamentoFilter(*this); }

      void process();

    private:
      laf_sample last_value_;
  };
} // namespace laf

#endif // TRIGGER_OPERATORS_H