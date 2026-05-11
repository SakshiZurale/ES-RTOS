# embedded-linux-porting
# Commands to Create and Save README File

Inside your repository terminal.

---

# Step 1 — Create README File

```bash id="jlwm3k"
nano README.md
```

---

# Step 2 — Paste README Content

Paste this:

````md id="jlwm6v"
# Embedded Linux Porting on ARM

## Aim
To port and boot an Embedded Linux kernel on ARM architecture using QEMU emulator.

---

## Tools Used
- GitHub Codespaces
- ARM Cross Compiler
- QEMU ARM Emulator
- Linux Kernel Source

---

## Commands Used

### Update Linux
```bash
sudo apt update
````

### Install Required Tools

```bash
sudo apt install gcc-arm-linux-gnueabi qemu-system-arm u-boot-tools build-essential git busybox cpio flex bison bc libssl-dev -y
```

### Clone Linux Kernel

```bash
git clone https://github.com/torvalds/linux.git
```

### Enter Linux Directory

```bash
cd linux
```

### Configure ARM Kernel

```bash
make ARCH=arm versatile_defconfig
```

### Build ARM Kernel

```bash
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- -j4
```

### Build Device Tree Files

```bash
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- dtbs
```

### Run ARM Linux Kernel

```bash
qemu-system-arm \
-M versatilepb \
-kernel arch/arm/boot/zImage \
-dtb arch/arm/boot/dts/arm/versatile-pb.dtb \
-append "console=ttyAMA0" \
-nographic \
-audio none
```

---

## Output

* ARM Linux kernel booted successfully.
* Linux initialized ARM hardware devices.
* Kernel panic occurred because root filesystem was not attached.

---

## Result

The Embedded Linux kernel was successfully cross-compiled and booted on ARM architecture using QEMU emulator.

````

---

# Step 3 — Save File

Press:

```text id="jlwm5q"
CTRL + O
ENTER
CTRL + X
````

---

# Step 4 — Add README to Git

```bash id="jlwm1y"
git add README.md
```

---

# Step 5 — Commit README

```bash id="jlwm4b"
git commit -m "Added README file"
```

---

# Step 6 — Push to GitHub

```bash id="jlwm9d"
git push
```

---

# Verify

Open your repository on [GitHub](https://github.com?utm_source=chatgpt.com)

You will see formatted `README.md` displayed automatically.
