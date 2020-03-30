// 引入逐行读取包
var readline = require('readline');

// 逐行读取接口
var rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

rl.setPrompt('input>');
rl.prompt();

// 当在终端输入一行字符+回车触发line事件，将此行字符串传入函数中作为参数
rl.on('line', function(line) {
	var str = line;
	console.log(MergeSpaces(str));//函数没有返回值，输出undefine
});

function MergeSpaces (str) {
	str = str.replace(/\s+/g,' ');// '\s'查找空白字符，g执行全局匹配，
	//正则表达式 var patt = /runoob/i  ，runoob是一个正则表达式主体(用于检索)，i是一个修饰符
	console.log(str);
}