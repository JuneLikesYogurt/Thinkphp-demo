<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>add</title>
</head>
<body>
    <form action="__URL__/create" method="post">
        姓名：<input type="text" name="username"/><br>
        性别：男<input type="radio" name="sex" value="1">女<input type="radio" name="sex" value="0"><br>
        <input type="submit" value="添加新用户">
    </form>
</body>
</html>