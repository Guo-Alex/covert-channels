/****************************/
/* THIS IS OPEN SOURCE CODE */
/****************************/

/* 
* File:    map-k8.h
* CVS:     $Id$
* Author:  Harald Servat
*          redcrash@gmail.com
*/

#ifndef FreeBSD_MAP_K8
#define FreeBSD_MAP_K8

enum NativeEvent_Value_K8Processor {
	PNE_K8_BU_CPU_CLK_UNHALTED = PAPI_NATIVE_MASK,
	PNE_K8_BU_FILL_REQUEST_L2_MISS,
	PNE_K8_BU_INTERNAL_L2_REQUEST,
	PNE_K8_DC_ACCESS,
	PNE_K8_DC_COPYBACK,
	PNE_K8_DC_DCACHE_ACCESSES_BY_LOCKS,
	PNE_K8_DC_DISPATCHED_PREFETCH_INSTRUCTIONS,
	PNE_K8_DC_L1_DTLB_MISS_AND_L2_DTLB_HIT,
	PNE_K8_DC_L1_DTLB_MISS_AND_L2_DTLB_MISS,
	PNE_K8_DC_MICROARCHITECTURAL_EARLY_CANCEL_OF_AN_ACCESS,
	PNE_K8_DC_MICROARCHITECTURAL_LATE_CANCEL_OF_AN_ACCESS,
	PNE_K8_DC_MISALIGNED_DATA_REFERENCE,
	PNE_K8_DC_MISS,
	PNE_K8_DC_ONE_BIT_ECC_ERROR,
	PNE_K8_DC_REFILL_FROM_L2,
	PNE_K8_DC_REFILL_FROM_SYSTEM,
	PNE_K8_FP_DISPATCHED_FPU_OPS,
	PNE_K8_FP_CYCLES_WITH_NO_FPU_OPS_RETIRED,
	PNE_K8_FP_DISPATCHED_FPU_FAST_FLAG_OPS,
	PNE_K8_FR_DECODER_EMPTY,
	PNE_K8_FR_DISPATCH_STALLS,
	PNE_K8_FR_DISPATCH_STALL_FOR_SEGMENT_LOAD,
	PNE_K8_FR_DISPATCH_STALL_FOR_SERIALIZATION,
	PNE_K8_FR_DISPATCH_STALL_FOR_BRANCH_ABORT_TO_RETIRE,
	PNE_K8_FR_DISPATCH_STALL_WHEN_FPU_IS_FULL,
	PNE_K8_FR_DISPATCH_STALL_WHEN_LS_IS_FULL,
	PNE_K8_FR_DISPATCH_STALL_WHEN_REORDER_BUFFER_IS_FULL,
	PNE_K8_FR_DISPATCH_STALL_WHEN_RESERVATION_STATIONS_ARE_FULL,
	PNE_K8_FR_DISPATCH_STALL_WHEN_WAITING_FOR_ALL_TO_BE_QUIET,
	PNE_K8_FR_DISPATCH_STALL_WHEN_WAITING_FAR_XFER_OR_RESYNC_BRANCH_PENDING,
	PNE_K8_FR_FPU_EXCEPTIONS,
	PNE_K8_FR_INTERRUPTS_MASKED_CYCLES,
	PNE_K8_FR_INTERRUPTS_MASKED_WHILE_PENDING_CYCLES,
	PNE_K8_FR_NUMBER_OF_BREAKPOINTS_FOR_DR0,
	PNE_K8_FR_NUMBER_OF_BREAKPOINTS_FOR_DR1,
	PNE_K8_FR_NUMBER_OF_BREAKPOINTS_FOR_DR2,
	PNE_K8_FR_NUMBER_OF_BREAKPOINTS_FOR_DR3,
	PNE_K8_FR_RETIRED_BRANCHES,
	PNE_K8_FR_RETIRED_BRANCHES_MISPREDICTED,
	PNE_K8_FR_RETIRED_FAR_CONTROL_TRANSFERS,
	PNE_K8_FR_RETIRED_FASTPATH_DOUBLE_OP_INSTRUCTIONS,
	PNE_K8_FR_RETIRED_FPU_INSTRUCTIONS,
	PNE_K8_FR_RETIRED_NEAR_RETURNS,
	PNE_K8_FR_RETIRED_NEAR_RETURNS_MISPREDICTED,
	PNE_K8_FR_RETIRED_RESYNCS,
	PNE_K8_FR_RETIRED_TAKEN_HARDWARE_INTERRUPTS,
	PNE_K8_FR_RETIRED_TAKEN_BRANCHES,
	PNE_K8_FR_RETIRED_TAKEN_BRANCHES_MISPREDICTED,
	PNE_K8_FR_RETIRED_TAKEN_BRANCHES_MISPREDICTED_BY_ADDR_MISCOMPARE,
	PNE_K8_FR_RETIRED_UOPS,
	PNE_K8_FR_RETIRED_X86_INSTRUCTIONS,
	PNE_K8_IC_FETCH,
	PNE_K8_IC_INSTRUCTION_FETCH_STALL,
	PNE_K8_IC_L1_ITLB_MISS_AND_L2_ITLB_HIT,
	PNE_K8_IC_L1_ITLB_MISS_AND_L2_ITLB_MISS,
	PNE_K8_IC_MICROARCHITECTURAL_RESYNC_BY_SNOOP,
	PNE_K8_IC_MISS,
	PNE_K8_IC_REFILL_FROM_L2,
	PNE_K8_IC_REFILL_FROM_SYSTEM,
	PNE_K8_RETURN_STACK_HITS,
	PNE_K8_RETURN_STACK_OVERFLOW,
	PNE_K8_LS_BUFFER2_FULL,
	PNE_K8_LS_LOCKED_OPERATION,
	PNE_K8_LS_MICROARCHITECTURAL_LATE_CANCEL,
	PNE_K8_LS_MICROARCHITECTURAL_RESYNC_BY_SELF_MODIFYING_CODE,
	PNE_K8_LS_MICROARCHITECTURAL_RESYNc_BY_SNOOP,
	PNE_K8_LS_RETIRED_CFLUSH_INSTRUCTIONS,
	PNE_K8_LS_RETIRED_CPUID_INSTRUCTIONS,
	PNE_K8_LS_SEGMENT_REGISTER_LOAD,
	PNE_K8_NB_MEMORY_CONTROLLER_BYPASS_SATURATION,
	PNE_K8_NB_MEMORY_CONTROLLER_DRAM_SLOTS_MISSED,
	PNE_K8_NB_MEMORY_CONTROLLER_PAGE_ACCESS_EVENT,
	PNE_K8_NB_MEMORY_CONTROLLER_PAGE_TABLE_OVERFLOW,
	PNE_K8_NB_PROBE_RESULT,
	PNE_K8_NB_SIZED_COMMANDS,
	PNE_K8_NB_MEMORY_CONTROLLER_TURNAROUND,
	PNE_K8_NB_HT_BUS0_BANDWIDTH,
	PNE_K8_NB_HT_BUS1_BANDWIDTH,
	PNE_K8_NB_HT_BUS2_BANDWIDTH,
	/* Special counters */
	PNE_K8_DC_REFILL_FROM_L2_MOES,
	PNE_K8_DC_REFILL_FROM_L2_OES,
	PNE_K8_DC_REFILL_FROM_L2_M,
	PNE_K8_DC_REFILL_FROM_SYSTEM_MOES,
	PNE_K8_DC_REFILL_FROM_SYSTEM_OES,
	PNE_K8_DC_REFILL_FROM_SYSTEM_M,
	PNE_K8_FP_DISPATCHED_FPU_MULS,
	PNE_K8_FP_DISPATCHED_FPU_ADDS,
	PNE_K8_FP_DISPATCHED_FPU_ADDS_AND_MULS,
	PNE_K8_NATNAME_GUARD
};

extern Native_Event_LabelDescription_t K8Processor_info[];
extern hwi_search_t K8Processor_map[];

#endif
