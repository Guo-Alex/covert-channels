/*
 * Copyright (c) 2012 Google, Inc
 * Contributed by Stephane Eranian <eranian@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of libpfm, a performance monitoring support library for
 * applications on Linux.
 *
 * PMU: snbep_unc_imc (Intel SandyBridge-EP IMC uncore PMU)
 */

static const intel_x86_umask_t snbep_unc_m_cas_count[]={
  { .uname = "ALL",
    .udesc  = "Counts total number of DRAM CAS commands issued on this channel",
    .ucode  = 0xf00,
    .uflags = INTEL_X86_NCOMBO | INTEL_X86_DFL,
  },
  { .uname = "RD",
    .udesc  = "Counts all DRAM reads on this channel, incl. underfills",
    .ucode  = 0x300,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "RD_REG",
    .udesc  = "Counts number of DRAM read CAS commands issued on this channel, incl. regular read CAS and those with implicit precharge",
    .ucode  = 0x100,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "RD_UNDERFILL",
    .udesc  = "Counts number of underfill reads issued by the memory controller",
    .ucode  = 0x200,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "WR",
    .udesc  = "Counts number of DRAM write CAS commands on this channel",
    .ucode  = 0xc00,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "WR_RMM",
    .udesc  = "Counts Number of opportunistic DRAM write CAS commands issued on this channel",
    .ucode  = 0x800,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "WR_WMM",
    .udesc  = "Counts number of DRAM write CAS commands issued on this channel while in Write-Major mode",
    .ucode  = 0x400,
    .uflags = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_umask_t snbep_unc_m_dram_refresh[]={
  { .uname = "HIGH",
    .udesc  = "TBD",
    .ucode  = 0x400,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "PANIC",
    .udesc  = "TBD",
    .ucode  = 0x200,
    .uflags = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_umask_t snbep_unc_m_major_modes[]={
  { .uname = "ISOCH",
    .udesc  = "Counts cycles in ISOCH Major maode",
    .ucode  = 0x800,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "PARTIAL",
    .udesc  = "Counts cycles in Partial Major mode",
    .ucode  = 0x400,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "READ",
    .udesc  = "Counts cycles in Read Major mode",
    .ucode  = 0x100,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "WRITE",
    .udesc  = "Counts cycles in Write Major mode",
    .ucode  = 0x200,
    .uflags = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_umask_t snbep_unc_m_power_cke_cycles[]={
  { .uname = "RANK0",
    .udesc  = "Count cycles for rank 0",
    .ucode  = 0x100,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "RANK1",
    .udesc  = "Count cycles for rank 1",
    .ucode  = 0x200,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "RANK2",
    .udesc  = "Count cycles for rank 2",
    .ucode  = 0x400,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "RANK3",
    .udesc  = "Count cycles for rank 3",
    .ucode  = 0x800,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "RANK4",
    .udesc  = "Count cycles for rank 4",
    .ucode  = 0x1000,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "RANK5",
    .udesc  = "Count cycles for rank 5",
    .ucode  = 0x2000,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "RANK6",
    .udesc  = "Count cycles for rank 6",
    .ucode  = 0x4000,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "RANK7",
    .udesc  = "Count cycles for rank 7",
    .ucode  = 0x8000,
    .uflags = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_umask_t snbep_unc_m_preemption[]={
  { .uname = "RD_PREEMPT_RD",
    .udesc  = "Counts read over read preemptions",
    .ucode  = 0x100,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "RD_PREEMPT_WR",
    .udesc  = "Counts read over write preemptions",
    .ucode  = 0x200,
    .uflags = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_umask_t snbep_unc_m_pre_count[]={
  { .uname = "PAGE_CLOSE",
    .udesc  = "Counts number of DRAM precharge commands sent on this channel as a result of the page close counter expiring",
    .ucode  = 0x200,
    .uflags = INTEL_X86_NCOMBO,
  },
  { .uname = "PAGE_MISS",
    .udesc  = "Counts number of DRAM precharge commands sent on this channel as a result of page misses",
    .ucode  = 0x100,
    .uflags = INTEL_X86_NCOMBO,
  },
};

static const intel_x86_entry_t intel_snbep_unc_m_pe[]={
  { .name   = "UNC_M_CLOCKTICKS",
    .desc   = "IMC Uncore clockticks",
    .modmsk = 0x0,
    .cntmsk = 0x100000000ull,
    .code = 0xff, /* perf pseudo encoding for fixed counter */
    .flags = INTEL_X86_FIXED,
  },
  { .name = "UNC_M_ACT_COUNT",
    .desc = "DRAM Activate Count",
    .code = 0x1,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_CAS_COUNT",
    .desc = "DRAM RD_CAS and WR_CAS Commands.",
    .code = 0x4,
    .cntmsk = 0xf,
    .ngrp = 1,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
    .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_m_cas_count),
    .umasks  = snbep_unc_m_cas_count
  },
  { .name = "UNC_M_DRAM_PRE_ALL",
    .desc = "DRAM Precharge All Commands",
    .code = 0x6,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_DRAM_REFRESH",
    .desc = "Number of DRAM Refreshes Issued",
    .code = 0x5,
    .cntmsk = 0xf,
    .ngrp = 1,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
    .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_m_dram_refresh),
    .umasks  = snbep_unc_m_dram_refresh
  },
  { .name = "UNC_M_ECC_CORRECTABLE_ERRORS",
    .desc = "ECC Correctable Errors",
    .code = 0x9,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_MAJOR_MODES",
    .desc = "Cycles in a Major Mode",
    .code = 0x7,
    .cntmsk = 0xf,
    .ngrp = 1,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
    .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_m_major_modes),
    .umasks  = snbep_unc_m_major_modes
  },
  { .name = "UNC_M_POWER_CHANNEL_DLLOFF",
    .desc = "Channel DLLOFF Cycles",
    .code = 0x84,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_POWER_CHANNEL_PPD",
    .desc = "Channel PPD Cycles",
    .code = 0x85,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_POWER_CKE_CYCLES",
    .desc = "CKE_ON_CYCLES by Rank",
    .code = 0x83,
    .cntmsk = 0xf,
    .ngrp = 1,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
    .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_m_power_cke_cycles),
    .umasks  = snbep_unc_m_power_cke_cycles
  },
  { .name = "UNC_M_POWER_CRITICAL_THROTTLE_CYCLES",
    .desc = "Critical Throttle Cycles",
    .code = 0x86,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_POWER_SELF_REFRESH",
    .desc = "Clock-Enabled Self-Refresh",
    .code = 0x43,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_POWER_THROTTLE_CYCLES",
    .desc = "Throttle Cycles for Rank 0",
    .code = 0x41,
    .cntmsk = 0xf,
    .ngrp = 1,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
    .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_m_power_cke_cycles),
    .umasks  = snbep_unc_m_power_cke_cycles /* identical to snbep_unc_m_power_cke_cycles */
  },
  { .name = "UNC_M_PREEMPTION",
    .desc = "Read Preemption Count",
    .code = 0x8,
    .cntmsk = 0xf,
    .ngrp = 1,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
    .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_m_preemption),
    .umasks  = snbep_unc_m_preemption
  },
  { .name = "UNC_M_PRE_COUNT",
    .desc = "DRAM Precharge commands.",
    .code = 0x2,
    .cntmsk = 0xf,
    .ngrp = 1,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
    .numasks = LIBPFM_ARRAY_SIZE(snbep_unc_m_pre_count),
    .umasks  = snbep_unc_m_pre_count
  },
  { .name = "UNC_M_RPQ_CYCLES_FULL",
    .desc = "Read Pending Queue Full Cycles",
    .code = 0x12,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_RPQ_CYCLES_NE",
    .desc = "Read Pending Queue Not Empty",
    .code = 0x11,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_RPQ_INSERTS",
    .desc = "Read Pending Queue Allocations",
    .code = 0x10,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_RPQ_OCCUPANCY",
    .desc = "Read Pending Queue Occupancy",
    .code = 0x80,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_WPQ_CYCLES_FULL",
    .desc = "Write Pending Queue Full Cycles",
    .code = 0x22,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_WPQ_CYCLES_NE",
    .desc = "Write Pending Queue Not Empty",
    .code = 0x21,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_WPQ_INSERTS",
    .desc = "Write Pending Queue Allocations",
    .code = 0x20,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_WPQ_OCCUPANCY",
    .desc = "Write Pending Queue Occupancy",
    .code = 0x81,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_WPQ_READ_HIT",
    .desc = "Write Pending Queue CAM Match",
    .code = 0x23,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
  { .name = "UNC_M_WPQ_WRITE_HIT",
    .desc = "Write Pending Queue CAM Match",
    .code = 0x24,
    .cntmsk = 0xf,
    .modmsk = SNBEP_UNC_IMC_ATTRS,
  },
};
