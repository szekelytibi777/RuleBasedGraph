ARG VARIANT="buster"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}
RUN apt update && apt install -y x11-apps && apt install -y graphviz