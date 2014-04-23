## Arch

```bash
gdisk /dev/sda

Number | Size      | Code | Name
------ | --------- | ---- | -----------------------
1      | 1007K     | EF02 | BIOS boot partition
2      | whatever  | 8300 | Linux filesystem (/boot)
3      | whatever  | 8300 | Linux filesystem (/)
4      | whatever  | 8200 | Linux swap


mkfs.ext4 /dev/sda*
mkswap   /dev/sda*

mount /dev/sda3 /mnt
mkdir /mnt/boot
mount /dev/sda2 /mnt/boot
swapon /dev/sda4

pacstrap -i /mnt base

genfstab -U /mnt >> /mnt/etc/fstab

arch-chroot /mnt

locale-gen
echo 'export LANG=en_US.UTF-8' > /etc/locale.conf
ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime

echo 'hao.me' > /etc/hostname

passwd

pacman -S grub-bios

grub-install --recheck /dev/sda
cp /usr/share/locale/en\@quot/LC_MESSAGES/grub.mo /boot/grub/locale/en.mo
grub-mkconfig -o /boot/grub/grub.cfg

```
