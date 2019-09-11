# Chocolatey

> **Chocolatey is a package manager for Windows (like apt-get or yum but for Windows).** It was designed to be a **decentralized** framework for quickly installing applications and tools that you need. It is built on the NuGet infrastructure currently using PowerShell as its focus for delivering packages from the distros to your door, err computer.

## Requirement
---

- Windows 7+ / Windows Server 2003+
- PowerShell v2+ (Not PowerShell Core yet though)
- .NET Framework 4+ (the installation will attempt to install .NET 4.0 if you do not have it installed)

That's it! All you need is choco.exe (that you get from the installation scripts) and you are good to go! No Visual Studio required.

## Installing
> Chocolatey installs in seconds. You are just a few steps from running choco right now!

1. First, ensure that you are using an administrative shell - you can also install as a non-admin, check out Non-Administrative Installation.
2. Copy the text specific to your command shell - **cmd.exe** or **powershell.exe**.
3. Paste the copied text into your shell and press Enter.
4. Wait a few seconds for the command to complete.
5. If you don't see any errors, you are ready to use Chocolatey! Type **_choco_** or **_choco -?_**

### Install with cmd.exe
``` shell
@"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"
```

### Install with PowerShell.exe
``` shell
Set-ExecutionPolicy Bypass -Scope Process -Force; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
```
