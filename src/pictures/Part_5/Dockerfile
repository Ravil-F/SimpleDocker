FROM nginx

WORKDIR /home/
COPY ./miniserver.c /home/miniserver.c
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh /home/run.sh
RUN apt-get update && apt-get install -y gcc spawn-fcgi libfcgi-dev \
    && chmod 777 /home/run.sh \
    && rm -rf /var/lib/apt/lists \
    && useradd barley \ 
    && chown -R barley:barley /etc/nginx/nginx.conf \
    && chown -R barley:barley /var/cache/nginx \
    && chown -R barley:barley /home \
    && touch /var/run/nginx.pid \
    && chown -R barley:barley /var/run/nginx.pid 
USER barley
ENTRYPOINT [ "sh", "/home/run.sh" ]
HEALTHCHECK --interval=30s --timeout=30s --start-period=5s --retries=3 CMD curl -f http://localhost:80 || exit 1
