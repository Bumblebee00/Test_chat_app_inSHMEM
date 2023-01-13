FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN mkdir /opt/diana/
WORKDIR /opt/diana/

RUN apt update

RUN apt install -y sudo git build-essential make cmake systemctl

COPY . .

RUN make configure

RUN cd example-library && make install

RUN make compile

# && sudo apt purge build-essential cmake make

CMD ./build/src/ExampleProgram/ExampleProgram
