<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>add</title>
</head>
<body>
    <form action="__URL__/create" method="post">
        用户名：<input type="text" name="username"/><br>
        内容： <input type="text" name="content"/><br>
        <input type="submit" value="添加留言">
    </form>
</body>
</html>