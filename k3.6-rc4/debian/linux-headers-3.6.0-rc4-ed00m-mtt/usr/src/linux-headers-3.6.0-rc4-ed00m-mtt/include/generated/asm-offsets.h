#ifndef __ASM_OFFSETS_H__
#define __ASM_OFFSETS_H__
/*
 * DO NOT MODIFY.
 *
 * This file was generated by Kbuild
 *
 */

#define IA32_SIGCONTEXT_ax 44 /* offsetof(struct sigcontext, ax)	# */
#define IA32_SIGCONTEXT_bx 32 /* offsetof(struct sigcontext, bx)	# */
#define IA32_SIGCONTEXT_cx 40 /* offsetof(struct sigcontext, cx)	# */
#define IA32_SIGCONTEXT_dx 36 /* offsetof(struct sigcontext, dx)	# */
#define IA32_SIGCONTEXT_si 20 /* offsetof(struct sigcontext, si)	# */
#define IA32_SIGCONTEXT_di 16 /* offsetof(struct sigcontext, di)	# */
#define IA32_SIGCONTEXT_bp 24 /* offsetof(struct sigcontext, bp)	# */
#define IA32_SIGCONTEXT_sp 28 /* offsetof(struct sigcontext, sp)	# */
#define IA32_SIGCONTEXT_ip 56 /* offsetof(struct sigcontext, ip)	# */

#define CPUINFO_x86 0 /* offsetof(struct cpuinfo_x86, x86)	# */
#define CPUINFO_x86_vendor 1 /* offsetof(struct cpuinfo_x86, x86_vendor)	# */
#define CPUINFO_x86_model 2 /* offsetof(struct cpuinfo_x86, x86_model)	# */
#define CPUINFO_x86_mask 3 /* offsetof(struct cpuinfo_x86, x86_mask)	# */
#define CPUINFO_hard_math 6 /* offsetof(struct cpuinfo_x86, hard_math)	# */
#define CPUINFO_cpuid_level 20 /* offsetof(struct cpuinfo_x86, cpuid_level)	# */
#define CPUINFO_x86_capability 24 /* offsetof(struct cpuinfo_x86, x86_capability)	# */
#define CPUINFO_x86_vendor_id 64 /* offsetof(struct cpuinfo_x86, x86_vendor_id)	# */

#define TI_sysenter_return 60 /* offsetof(struct thread_info, sysenter_return)	# */
#define TI_cpu 16 /* offsetof(struct thread_info, cpu)	# */

#define PT_EBX 0 /* offsetof(struct pt_regs, bx)	# */
#define PT_ECX 4 /* offsetof(struct pt_regs, cx)	# */
#define PT_EDX 8 /* offsetof(struct pt_regs, dx)	# */
#define PT_ESI 12 /* offsetof(struct pt_regs, si)	# */
#define PT_EDI 16 /* offsetof(struct pt_regs, di)	# */
#define PT_EBP 20 /* offsetof(struct pt_regs, bp)	# */
#define PT_EAX 24 /* offsetof(struct pt_regs, ax)	# */
#define PT_DS 28 /* offsetof(struct pt_regs, ds)	# */
#define PT_ES 32 /* offsetof(struct pt_regs, es)	# */
#define PT_FS 36 /* offsetof(struct pt_regs, fs)	# */
#define PT_GS 40 /* offsetof(struct pt_regs, gs)	# */
#define PT_ORIG_EAX 44 /* offsetof(struct pt_regs, orig_ax)	# */
#define PT_EIP 48 /* offsetof(struct pt_regs, ip)	# */
#define PT_CS 52 /* offsetof(struct pt_regs, cs)	# */
#define PT_EFLAGS 56 /* offsetof(struct pt_regs, flags)	# */
#define PT_OLDESP 60 /* offsetof(struct pt_regs, sp)	# */
#define PT_OLDSS 64 /* offsetof(struct pt_regs, ss)	# */

#define IA32_RT_SIGFRAME_sigcontext 164 /* offsetof(struct rt_sigframe, uc.uc_mcontext)	# */

#define TSS_sysenter_sp0 -8572 /* offsetof(struct tss_struct, x86_tss.sp0) - sizeof(struct tss_struct)	# */

#define __NR_syscall_max 349 /* sizeof(syscalls) - 1	# */
#define NR_syscalls 350 /* sizeof(syscalls)	# */

#define TI_flags 8 /* offsetof(struct thread_info, flags)	# */
#define TI_status 12 /* offsetof(struct thread_info, status)	# */
#define TI_addr_limit 24 /* offsetof(struct thread_info, addr_limit)	# */
#define TI_preempt_count 20 /* offsetof(struct thread_info, preempt_count)	# */

#define crypto_tfm_ctx_offset 48 /* offsetof(struct crypto_tfm, __crt_ctx)	# */

#define pbe_address 0 /* offsetof(struct pbe, address)	# */
#define pbe_orig_address 4 /* offsetof(struct pbe, orig_address)	# */
#define pbe_next 8 /* offsetof(struct pbe, next)	# */

#define PARAVIRT_enabled 8 /* offsetof(struct pv_info, paravirt_enabled)	# */
#define PARAVIRT_PATCH_pv_cpu_ops 16 /* offsetof(struct paravirt_patch_template, pv_cpu_ops)	# */
#define PARAVIRT_PATCH_pv_irq_ops 168 /* offsetof(struct paravirt_patch_template, pv_irq_ops)	# */
#define PV_IRQ_irq_disable 8 /* offsetof(struct pv_irq_ops, irq_disable)	# */
#define PV_IRQ_irq_enable 12 /* offsetof(struct pv_irq_ops, irq_enable)	# */
#define PV_CPU_iret 136 /* offsetof(struct pv_cpu_ops, iret)	# */
#define PV_CPU_irq_enable_sysexit 124 /* offsetof(struct pv_cpu_ops, irq_enable_sysexit)	# */
#define PV_CPU_read_cr0 12 /* offsetof(struct pv_cpu_ops, read_cr0)	# */
#define PV_MMU_read_cr2 0 /* offsetof(struct pv_mmu_ops, read_cr2)	# */

#define XEN_vcpu_info_mask 1 /* offsetof(struct vcpu_info, evtchn_upcall_mask)	# */
#define XEN_vcpu_info_pending 0 /* offsetof(struct vcpu_info, evtchn_upcall_pending)	# */

#define BP_scratch 484 /* offsetof(struct boot_params, scratch)	# */
#define BP_loadflags 529 /* offsetof(struct boot_params, hdr.loadflags)	# */
#define BP_hardware_subarch 572 /* offsetof(struct boot_params, hdr.hardware_subarch)	# */
#define BP_version 518 /* offsetof(struct boot_params, hdr.version)	# */
#define BP_kernel_alignment 560 /* offsetof(struct boot_params, hdr.kernel_alignment)	# */
#define BP_pref_address 600 /* offsetof(struct boot_params, hdr.pref_address)	# */
#define BP_code32_start 532 /* offsetof(struct boot_params, hdr.code32_start)	# */

#endif
