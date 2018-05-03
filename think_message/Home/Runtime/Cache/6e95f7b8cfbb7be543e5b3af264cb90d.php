<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>Top</title>
</head>
<body>
	<h1>ThinkPHP留言板系统</h1>
	<p>欢迎你　<?php echo (session('username')); ?>　<a href="__APP__/Login/doLogout" target="_top">退出</a></p>
</body>
</html>