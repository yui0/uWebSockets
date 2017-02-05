// g++ -IuWS -o uws-server uws-server.cpp uWS/Extensions.cpp uWS/Group.cpp uWS/HTTPSocket.cpp uWS/Hub.cpp uWS/Networking.cpp uWS/Node.cpp uWS/Socket.cpp uWS/WebSocket.cpp uWS/WebSocketImpl.cpp uWS/uUV.cpp -luv -lssl -lcrypto -lz
#include <fstream>
#include <uWS.h>

std::string read(const char *name)
{
	std::ifstream ifs(name);
	if (ifs.fail()) {
		std::cerr << name << " failed!" << std::endl;
		return "";
	}
	std::istreambuf_iterator<char> it(ifs);
	std::istreambuf_iterator<char> last;
	std::string str(it, last);
	return str;
}

int main()
{
	uWS::Hub h;

	h.onMessage([](uWS::WebSocket<uWS::SERVER> ws, char *message, size_t length, uWS::OpCode opCode) {
		ws.send(message, length, opCode);
	});

	h.onHttpRequest([](uWS::HttpResponse *res, uWS::HttpRequest req, char *data, size_t length, size_t remainingBytes) {
		std::cout << req.getUrl().toString() << std::endl;

		std::string s;
		if (req.getUrl().toString() == "/") {
			s = "webroot/index.html";
		} else {
			s = "webroot" + req.getUrl().toString();
		}
		s = read(s.c_str());
		res->end(s.data(), s.length());
	});

	h.listen(3000);
	h.run();
}
