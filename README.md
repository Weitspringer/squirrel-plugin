# Squirrel - Carbon-Aware Slurm Scheduling
Unlock the power of sustainable computing with Squirrel, a carbon-aware scheduler plugin for Slurm. Optimize your workload distribution to reduce the environmental impact of your computing tasks.

## Requirements
Before building and installing the Slurm scheduler plugin, ensure that the following packages and tools are installed on your system:

### Slurm
Ensure you use this repository's correct branch/tag corresponding to your Slurm version, e.g., `slurm-24-05-0-1`. You also need access to the source code.

### General Development Tools
- **C Compiler**: The source code must be compiled using a C compiler like GCC (GNU Compiler Collection).
- **C++ Compiler**: A C++ compiler is necessary for compiling any C++ components.
- **Autotools**: The GNU build system tools, including `autoconf`, `automake`, and `libtool`, are required for generating the build system files.
- **Make**: A build automation tool to direct the build process. 

On Debian-based systems, you can install these tools using the following command:
```bash
sudo apt-get install build-essential autoconf automake libtool
```

On Red Hat-based systems:
```bash
sudo yum groupinstall "Development Tools"
sudo yum install autoconf automake libtool
```

### GTK+ 2.0 Development Tools
Slurm requires GTK+ 2.0 development libraries. Ensure the following packages are installed:
- **GTK+ 2.0 Library**: The core library for the GTK+ 2.0 toolkit.
- **GTK+ 2.0 Development Package**: Includes headers and other necessary files for developing with GTK+ 2.0.

On Debian-based systems, you can install these using:
```bash
sudo apt-get install libgtk2.0-dev
```

On Red Hat-based systems:
```bash
sudo yum install gtk2-devel
```

## Directory Structure

- `slurm/src/plugins/sched/Makefile.am`: Main Makefile for the scheduler plugins.
- `slurm/src/plugins/sched/squirrel/`: Directory containing the Squirrel plugin source code and Makefile.

## Building the Squirrel Plugin

1. **Copy the contents of this repository into your Slurm source directory:**
    ```bash
    cp -r slurm/ /path/to/your/slurm/
    ```
> [!WARNING]
> This overwrites the file `src/plugins/sched/Makefile.am`. In case you have other scheduler plugins besides the default ones (backfill, builtin), you have to adjust this file after this step to include the subdirectories of other plugins.

2. **Navigate to the Slurm source directory:**

    ```bash
    cd /path/to/your/slurm
    ```

3. **Modify `configure.ac` to include the Squirrel plugin:**

    Open `configure.ac` in a text editor and add the following line to ensure the Squirrel plugin is included in the build process. Make sure it is added to the `AC_CONFIG_FILES` section, which might look something like this:

    ```m4
    AC_CONFIG_FILES([
                     ...
                     src/plugins/sched/Makefile
                     src/plugins/sched/backfill/Makefile
                     src/plugins/sched/builtin/Makefile
                     src/plugins/sched/squirrel/Makefile
                     ...
                    ])
    ```

4. **Run the build tools to generate the configure script:**

    ```bash
    autoreconf -i
    ```

5. **Configure the Slurm build:**

    ```bash
    ./configure
    ```

6. **Install the plugins:**

    ```bash
    make install
    ```

## Using the Plugin

1. **Update the Slurm configuration to use the Squirrel scheduler:**

    Edit the Slurm configuration file (e.g., `/etc/slurm/slurm.conf`) to include the Squirrel scheduler plugin.

    ```ini
    SchedulerType=sched/squirrel
    ```

2. **Restart the Slurm controller to apply the changes:**

    ```bash
    sudo systemctl restart slurmctld
    ```
