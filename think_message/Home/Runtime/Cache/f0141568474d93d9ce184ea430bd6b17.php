<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>Login</title>
	<link rel="stylesheet" type="text/css" href="__PUBLIC__/CSS/basic.css" />
	<link rel="stylesheet" type="text/css" href="__PUBLIC__/CSS/Home/login.css" />
	<script type="text/javascript" src="__PUBLIC__/JS/jquery.js"></script>

	<script type="text/javascript">
		$(function(){
			$('img[title="login"]').click(function(){
				$('form[name="myForm"]').submit();
			});
			$('img[class="register"]').click(function(){
				window.location="__APP__/Register/reg";
			});
		});
	</script>
</head>
<body>
	<form action="__URL__/doLogin" method="post" name="myForm">
		用户名：<input type="text" name="username"><br>
		密　码：<input type="password" name="password"><br>
		验证码：<input type="text" name="code"/><img src="__APP__/Public/code?w=30&h=30" onclick="this.src=this.src+'?'+Math.random()"/><br>
		<img src="__PUBLIC__/Images/login.gif" title="login" class="submit">
		<img src="__PUBLIC__/Images/register.gif" class="register">

	</form>
</body>
</html>