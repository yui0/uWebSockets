# uWebSockets
`µWS` is one of the most lightweight, efficient & scalable WebSocket & HTTP server implementations available. It features an easy-to-use, fully async object-oriented interface and scales to millions of connections using only a fraction of memory compared to the competition. While performance and scalability are two of our top priorities, we consider security, stability and standards compliance paramount. License is zlib/libpng (very permissive & suits commercial applications).

* Autobahn tests [all pass](http://htmlpreview.github.io/?https://github.com/uWebSockets/uWebSockets/blob/master/autobahn/index.html).
* Significantly outperforms `WebSocket++`, `libwebsockets`, `Beast`, `Crow`, `Gorilla`, `Kaazing Gateway`, `ws` and `Socket.IO` in every tested dimension (see benchmark table below).
* Outperforms `Apache`, `Node.js`, `NGINX` by at least 4x in HTTP requests per second.
* Linux, OS X & Windows support.
* Valgrind / AddressSanitizer clean.
* Built-in load balancing and multi-core scalability.
* SSL/TLS support & integrates with foreign HTTPS servers.
* Permessage-deflate built-in.
* Node.js binding exposed as the well-known `ws` interface (`uws` is at least 20x faster and 20x more scalable).
