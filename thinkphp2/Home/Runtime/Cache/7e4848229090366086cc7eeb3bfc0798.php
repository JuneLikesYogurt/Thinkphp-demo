<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<!-- <link rel="stylesheet" type="text/css" href="__PUBLIC__/CSS/test.css">
	<script type="text/javascript" src="__PUBLIC__/JS/test.js"></script> -->

	<!-- <script type="text/javascript" src="/thinkphp2/Public/JS/test.js"></script> -->
	<!-- 导入Public文件夹下面的JS目录中的test.js文件，import标签不可以省略type属性-->
	<!-- <script type="text/javascript" src="./Other/JS/my.js"></script>
	<link rel="stylesheet" type="text/css" href="./Other/CSS/my.css" /> -->

	<link rel="stylesheet" type="text/css" href="__PUBLIC__/CSS/test.css" />
	<!-- <script type="text/javascript" src="__PUBLIC__/JS/test.js"></script> -->

	<title>Index</title>
</head>
<body>
	<!-- <p><?php echo ($name); ?></p> -->

	<!-- <?php if($sex == "男"): ?>男人是泥巴做的
	<?php else: ?>
		女人是水做的<?php endif; ?> -->

	<!-- <?php if($age < 18): ?>未成年
		<?php elseif($age == 18): ?>
		青春年少
		<?php else: ?>
		成年<?php endif; ?> -->

<!-- 	<?php switch($$number): case "1": ?>一个和尚挑水吃<?php break;?>
		<?php case "2": ?>两个和尚抬水吃<?php break;?>
		<?php case "3": ?>三个和尚没水吃<?php break;?>
		<?php default: ?>这是默认值<?php endswitch;?>	 -->

	<!-- <table border="1" width="500">
		<?php $__FOR_START_1985__=10;$__FOR_END_1985__=00;for($j=$__FOR_START_1985__;$j > $__FOR_END_1985__;$j+=-2){ ?><tr><td><?php echo ($j); ?></td><td>abc</td></tr><?php } ?>
	</table> -->

	<!-- <?php if(is_array($list)): $i = 0; $__LIST__ = array_slice($list,1,3,true);if( count($__LIST__)==0 ) : echo "" ;else: foreach($__LIST__ as $key=>$v): $mod = ($i % 2 );++$i; echo ($v); ?><br><?php endforeach; endif; else: echo "" ;endif; ?> -->

	<!-- <?php if(is_array($list)): $i = 0; $__LIST__ = $list;if( count($__LIST__)==0 ) : echo "" ;else: foreach($__LIST__ as $key=>$v): $mod = ($i % 2 );++$i; echo ($v["username"]); ?><br><?php endforeach; endif; else: echo "" ;endif; ?> -->
	
	<!-- <?php if(is_array($list)): foreach($list as $k=>$v): echo ($k); ?>-----<?php echo ($v); ?><br><?php endforeach; endif; ?> -->

	<!-- 
	<table border="1" width="500">
		<?php if(is_array($list)): foreach($list as $key=>$v): ?><tr>
				<td><?php echo ($v["id"]); ?></td>
				<td><?php echo ($v["username"]); ?></td>
				<td><?php echo ($v["password"]); ?></td> 
				<?php if($v["sex"] == 1): ?><td>男</td>
					<?php else: ?>
						<td>女</td><?php endif; ?>
			</tr><?php endforeach; endif; ?>
	</table> -->

	<p>这里是首页</p>
	<a href="__URL__/next">跳转到下一页</a>
</body>
</html>