FROM alpine:3.16

RUN apk --no-cache add curl
RUN curl -L https://downloads.portainer.io/portainer-agent-stack.yml -o /portainer-agent-stack.yml

RUN apk --no-cache add docker-compose

CMD ["docker-compose", "-f", "/portainer-agent-stack.yml", "up"]