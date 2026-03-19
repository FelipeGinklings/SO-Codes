# Dockerfile
FROM ubuntu:22.04

# Install zsh and essential tools
RUN apt-get update && apt-get install -y \
    zsh \
    git \
    curl \
    wget \
    vim \
    nano \
    htop \
    build-essential \
    zsh-syntax-highlighting \
    zsh-autosuggestions \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Install oh-my-zsh
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

# Set zsh as default shell
SHELL ["/bin/zsh", "-c"]
RUN chsh -s $(which zsh)

# cd ~
# ssh-keygen -t ed25519 -C "felipe.ginklings@gmail.com"
# nano .zshrc
# git clone git@github.com:FelipeGinklings/zsh-backup.git
# mv zsh-backup .zsh-backup
# cd zsh-backup
# cp -rf .zsh* ../
# cp -r custom ../.oh-my-zsh
# source ~/.zshrc
# cat >> ~/.zshrc << 'EOF'
# 
# source /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
# source /usr/share/zsh-autosuggestions/zsh-autosuggestions.zsh
# EOF
# export PATH="$HOME/bin:$PATH"

# Create working directory
WORKDIR /workspace


# Keep container running
CMD ["zsh"]