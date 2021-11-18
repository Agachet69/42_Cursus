FROM debian:buster

RUN apt-get update -y \
&& apt-get install -y \
nginx openssl

COPY ./default ./etc/nginx/sites-enabled/
COPY ./start.sh ./
COPY test.html ./var/www/html/index.html

EXPOSE 80
EXPOSE 443

CMD  ./start.sh
