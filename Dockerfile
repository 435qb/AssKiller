FROM drogonframework/drogon:latest

ENV IROOT=/install

ENV ASSKILLER_ROOT="$IROOT/asskiller"

RUN git clone https://github.com/435qb/AssKiller $ASSKILLER_ROOT

WORKDIR $ASSKILLER_ROOT

RUN ./build.sh
