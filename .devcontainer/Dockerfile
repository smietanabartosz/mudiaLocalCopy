FROM ubuntu:jammy

USER root

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

COPY library-scripts/*.sh /tmp/library-scripts/
RUN apt update \
 && bash /tmp/library-scripts/common-debian.sh

# Required to access USB devices
RUN usermod -aG dialout ${USERNAME}
RUN usermod -aG plugdev ${USERNAME}

RUN ln -fs /usr/share/zoneinfo/Europe/Warsaw /etc/localtime
ENV DEBIAN_FRONTEND=noninteractive

RUN apt install -y build-essential \
                       bash-completion git git-gui tig \
                       minicom vim zip unzip \
&&  apt install -y  apt-utils software-properties-common build-essential ca-certificates clang-format-12 clang-tidy-12 \
                        curl doxygen g++-10 gcc-10 gdb git libgtkmm-3.0-dev libblkid-dev libfdisk-dev libfuse-dev \
                        mtools ninja-build pkg-config pulseaudio libpulse0 libpulse-dev python3-magic python3-pip python3-requests \
                        rhash rsync tzdata tar wget zip fdisk luarocks libpython2.7

# RUN wget https://www.segger.com/downloads/jlink/JLink_Linux_V634f_x86_64.deb
# RUN apt install -y ./JLink_Linux_V634f_x86_64.deb

# Required by Python3 because of Grinn CA
ENV REQUESTS_CA_BUNDLE="/etc/ssl/certs/ca-certificates.crt"

USER ${USERNAME}

# Setting the ENTRYPOINT to docker-init.sh will configure non-root access to
# the Docker socket if "overrideCommand": false is set in devcontainer.json.
# The script will also execute CMD if you need to alter startup behaviors.
ENTRYPOINT [ "/usr/local/share/docker-init.sh" ]
CMD [ "sleep", "infinity" ]
