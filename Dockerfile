FROM centos
RUN yum -y install sudo
RUN sudo yum -y update
RUN sudo yum -y install vim
RUN sudo yum -y install passwd
COPY test /test
CMD ./test
