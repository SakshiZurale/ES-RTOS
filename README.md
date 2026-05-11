# kernel-driver-experiment

# Kernel-Space Device Driver Experiment — All Commands with Simple Explanation

---

# 1. Update Linux Packages

```bash
sudo apt update
```

## Why Used?

Updates Linux package information before installing software.

---

# 2. Install Required Tools

```bash
sudo apt install build-essential linux-headers-$(uname -r) kmod -y
```

## Why Used?

Installs required tools for kernel driver development.

| Package         | Purpose                            |
| --------------- | ---------------------------------- |
| build-essential | GCC compiler and build tools       |
| linux-headers   | Kernel header files                |
| kmod            | Provides insmod and rmmod commands |

---

# 3. Create Driver Source File

```bash
nano mydriver.c
```

## Why Used?

Creates C file for Linux kernel driver code.

---

# 4. Driver Code

```c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init mydriver_init(void)
{
    printk(KERN_ALERT "Driver Loaded Successfully\n");
    return 0;
}

static void __exit mydriver_exit(void)
{
    printk(KERN_ALERT "Driver Removed Successfully\n");
}

module_init(mydriver_init);
module_exit(mydriver_exit);

MODULE_LICENSE("GPL");
```

## Why Used?

Creates a simple Linux kernel module.

### Important Functions

| Function        | Purpose                   |
| --------------- | ------------------------- |
| mydriver_init() | Runs when driver loads    |
| mydriver_exit() | Runs when driver removes  |
| printk()        | Prints kernel message     |
| module_init()   | Registers load function   |
| module_exit()   | Registers remove function |

---

# 5. Save File in Nano

```text
CTRL + O
ENTER
CTRL + X
```

## Why Used?

| Key      | Purpose          |
| -------- | ---------------- |
| CTRL + O | Save file        |
| ENTER    | Confirm filename |
| CTRL + X | Exit editor      |

---

# 6. Create Makefile

```bash
nano Makefile
```

## Why Used?

Creates build instructions for kernel module compilation.

---

# 7. Makefile Code

```makefile
obj-m += mydriver.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

## Why Used?

| Part         | Purpose                 |
| ------------ | ----------------------- |
| obj-m        | Defines kernel module   |
| make modules | Builds driver           |
| make clean   | Removes generated files |

---

# 8. Build Driver

```bash
make
```

## Why Used?

Compiles driver source code into kernel module.

### Output Generated

```text
mydriver.ko
```

`.ko` means Linux kernel object/module.

---

# 9. Check Generated Files

```bash
ls
```

## Why Used?

Displays all files in current folder.

Expected important file:

```text
mydriver.ko
```

---

# 10. Load Driver into Kernel

```bash
sudo insmod mydriver.ko
```

## Why Used?

Inserts driver into Linux kernel memory.

### Meaning

* Driver becomes active
* Kernel starts using module

---

# 11. Show Success Message

```bash
echo "Driver Loaded Successfully"
```

## Why Used?

Displays visible message on terminal.

---

# 12. Verify Driver Loaded

```bash
lsmod | grep mydriver
```

## Why Used?

Checks whether driver is currently loaded.

Expected output:

```text
mydriver
```

---

# 13. Remove Driver

```bash
sudo rmmod mydriver
```

## Why Used?

Removes driver from Linux kernel.

---

# 14. Show Remove Message

```bash
echo "Driver Removed Successfully"
```

## Why Used?

Displays remove confirmation on terminal.

---

# 15. Verify Driver Removed

```bash
lsmod | grep mydriver
```

## Why Used?

Checks whether driver is removed.

No output means:

* driver removed successfully

---

# 16. Save Files to GitHub

```bash
git add .
```

## Why Used?

Adds all files for saving.

---

# 17. Create Commit

```bash
git commit -m "Kernel driver experiment completed"
```

## Why Used?

Creates permanent save point.

---

# 18. Upload to GitHub

```bash
git push
```

## Why Used?

Uploads experiment files to GitHub repository.

---

# Complete Experiment Flow

| Step               | Command                   | Purpose              |
| ------------------ | ------------------------- | -------------------- |
| Install tools      | `sudo apt install ...`    | Install driver tools |
| Create source file | `nano mydriver.c`         | Write driver code    |
| Create Makefile    | `nano Makefile`           | Build instructions   |
| Compile driver     | `make`                    | Generate `.ko` file  |
| Load driver        | `sudo insmod mydriver.ko` | Insert into kernel   |
| Check driver       | `lsmod`                   | Verify loaded        |
| Remove driver      | `sudo rmmod mydriver`     | Remove from kernel   |
| Save to GitHub     | `git push`                | Store experiment     |

---

# Very Simple Meaning of Experiment

You created a Linux kernel driver, compiled it into a kernel module, loaded it into the Linux kernel, verified it worked, and removed it safely. This demonstrates how Linux communicates with hardware using device drivers.
