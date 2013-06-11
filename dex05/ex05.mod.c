#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x41572473, "module_layout" },
	{ 0x8b299257, "misc_deregister" },
	{ 0x37a0cba, "kfree" },
	{ 0xe4255c44, "misc_register" },
	{ 0xa963fd01, "kmem_cache_alloc_trace" },
	{ 0xac283e02, "kmalloc_caches" },
	{ 0x4f8b5ddb, "_copy_to_user" },
	{ 0xf9a482f9, "msleep" },
	{ 0x4f6b400b, "_copy_from_user" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x57b09822, "up" },
	{ 0x670c0597, "down_interruptible" },
	{ 0x27e1a049, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "C5ACDF6E3A09163F05FBF85");
