////////////////////////////////////////////////////////////////////////////////
//                                            __ _      _     _               //
//                                           / _(_)    | |   | |              //
//                __ _ _   _  ___  ___ _ __ | |_ _  ___| | __| |              //
//               / _` | | | |/ _ \/ _ \ '_ \|  _| |/ _ \ |/ _` |              //
//              | (_| | |_| |  __/  __/ | | | | | |  __/ | (_| |              //
//               \__, |\__,_|\___|\___|_| |_|_| |_|\___|_|\__,_|              //
//                  | |                                                       //
//                  |_|                                                       //
//                                                                            //
//                                                                            //
//              Peripheral-NTM for MPSoC                                      //
//              Neural Turing Machine for MPSoC                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2022-2025 by the author(s)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////
// Author(s):
//   Paco Reina Campo <pacoreinacampo@queenfield.tech>

`include "ntm_uvm_sequence_item.sv"
`include "ntm_uvm_sequencer.sv"
`include "ntm_uvm_sequence.sv"
`include "ntm_uvm_driver.sv"
`include "ntm_uvm_monitor.sv"
`include "ntm_uvm_scoreboard.sv"
`include "ntm_uvm_agent.sv"
`include "ntm_uvm_environment.sv"

class ntm_uvm_test extends uvm_test;
  // Environment method instantiation
  ntm_uvm_environment environment;

  // Sequence method instantiation
  ntm_uvm_sequence   base_sequence;

  // Utility declaration
  `uvm_component_utils(ntm_uvm_test)

  // Constructor
  function new(string name = "base_test", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  // Build phase
  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    // Create environment method
    environment = ntm_uvm_environment::type_id::create("environment", this);
  endfunction

  // Run phase
  task run_phase(uvm_phase phase);
    phase.raise_objection(this);

    // Create sequence method
    base_sequence = ntm_uvm_sequence::type_id::create("base_sequence");

    repeat (10) begin
      #5;
      base_sequence.start(environment.agent.sequencer);
    end

    phase.drop_objection(this);
    `uvm_info(get_type_name, "End of TestCase", UVM_LOW);
  endtask
endclass
