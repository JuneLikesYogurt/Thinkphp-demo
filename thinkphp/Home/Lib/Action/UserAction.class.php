<?php
    class UserAction extends Action{
    	public function index(){
    		//echo "你好！";
    		$m=M('User');
    		$arr=$m->select();
    		//var_dump($arr);
    		$this->assign('data',$arr);
    		$this->display();
    	}
    	public function del(){
    		$m=M('User');
    		$id=$_GET['id'];
    		$count=$m->delete($id);
    		echo $count;
    		if($count>0){
    			$this->success('数据删除成功');
    		}
    		else{
    			$this->error('数据删除失败');
    		}
    	}
    	//显示修改页面
    	public function modify(){
    		$id=$_GET['id'];
    		$m=M('User');
    		$arr=$m->find($id);
    		$this->assign('data',$arr);
    		$this->display();
    	}
    	public function update(){
    		$m=M('User');
    		$date['id']=$_POST['id'];
    		$date['username']=$_POST['username'];
    		$date['sex']=$_POST['sex'];
    		$count=$m->save($date);
    		if($count>0){
    			$this->success('数据修改成功','index');
    		}
    		else{
    			$this->error('数据修改失败');
    		}
    	}
    	//添加页面
    	public function add(){
                $this->display();
    	}
    	public function create(){
    		$m=M('User');
    		$m->username=$_POST['username'];
    		$m->sex=$_POST['sex'];
    		$idNum=$m->add();
    		if($idNum>0){
    			$this->success('数据添加成功','index');
    		}
    		else{
    			$this->error('数据添加失败');
    		}
    	}
        //search方法实现搜索
        public function search(){
            //var_dump($_POST);
            //获取post的数据，根据数据组装查询的条件，根据条件从数据库中获取数据，返回给页面中遍历
            $where['username']=array('like',"%{$_POST['username']}%");
            $where['sex']=array('eq',$_POST['sex']);

            $m=M('User');
            $arr=$m->where($where)->select();
            $this->assign('data',$arr);
            $this->display('index');
        }

        public function demo(){
        	$m=M('User');
        	$arr=$m->select();
        	dump($arr);
        	$this->show('abbc');
        }
    }
?>