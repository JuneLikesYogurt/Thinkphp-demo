var http = require('http');

http.createServer(function (request,response) {

	//发送http头部
	//http 状态值：200：ok
	//内容类型：text/plain
	response.writeHead(200,{'Content-Type': 'text/plain'});

	//发送相应数据 "hello world"
	response.end('hello world\n');
}).listen(8888);

//终端打印如下信息
console.log('Server running at http://127.0.0.1:8888/');