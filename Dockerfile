FROM resin/armv7hf-debian:jessie

COPY qemu-injector.so /qemu-injector.so

COPY static-sh  /bin/sh

ENV LD_PRELOAD /qemu-injector.so

RUN echo this is amazing

RUN /bin/bash -c 'echo child process is even more amazing'
