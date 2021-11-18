echo coucou

openssl req -newkey rsa:4096 \
            -x509 \
            -sha256 \
            -days 365 \
            -nodes \
            -out /etc/nginx/example.crt \
            -keyout /etc/nginx/example.key \
            -subj "/C=FR/ST=Lyon/L=Lyon/O=42School/OU=agachet/CN=agachet"

service nginx start

sleep infinity

