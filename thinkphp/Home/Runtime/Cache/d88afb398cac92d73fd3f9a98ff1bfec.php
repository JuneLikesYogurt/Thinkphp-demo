<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<title>Modify</title>
</head>
<body>
    <form action="/thinkphp/index.php/User/update" method="post">
        <input type="hidden" name="id" value="<?php echo ($data["id"]); ?>">
    	姓名：<input type="text" name="username" value="<?php echo ($data["username"]); ?>" /><br/>
    	性别：男<input type="radio" name="sex" value="1"> 女<input type="radio" name="sex" value="0"/><br/>
    	<input type="submit" value="提交修改"/>
    </form>
</body>
</html>