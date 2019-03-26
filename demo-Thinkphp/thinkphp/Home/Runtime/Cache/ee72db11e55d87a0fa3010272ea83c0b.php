<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>Modify</title>
</head>
<body>
    <form action="/thinkphp/index.php/bbs/update" method="post">
        <input type="hidden" name="id" value="<?php echo ($data["id"]); ?>">
    	用户名：<input type="text" name="username" value="<?php echo ($data["username"]); ?>" /><br/>
    	内容： <input type="text" name="content"/><br/>
    	<input type="submit" value="提交修改"/>
    </form>
</body>
</html>