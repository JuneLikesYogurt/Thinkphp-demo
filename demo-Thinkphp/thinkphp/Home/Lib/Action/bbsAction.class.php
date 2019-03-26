<?php
    class bbsAction extends Action{
    	public function index(){
    		$m=M('Bbs');
    		$arr=$m->select();
    		$this->assign('data',$arr);
    		$this->display();
    	}
	    //添加页面
		public function add(){
		        $this->display();
		}
		public function create(){
			$m=M('Bbs');
			$m->username=$_POST['username'];
			$m->content=$_POST['content'];
			$idNum=$m->add();
			if($idNum>0){
				$this->success('留言添加成功','index');
			}
			else{
				$this->error('留言添加失败');
			}
		}
		public function del(){
    		$m=M('Bbs');
    		$id=$_GET['id'];
    		$count=$m->delete($id);
    		echo $count;
    		if($count>0){
    			$this->success('留言删除成功');
    		}
    		else{
    			$this->error('留言删除失败');
    		}
    	}
    	//显示修改页面
    	public function modify(){
    		$content=$_GET['content'];
    		$m=M('Bbs');
    		$arr=$m->find($content);
    		$this->assign('data',$arr);
    		$this->display();
    	}
    	public function update(){
    		$m=M('Bbs');
    		$date['id']=$_POST['id'];
    		$date['username']=$_POST['username'];
    		$date['content']=$_POST['content'];
    		$count=$m->save($date);
    		if($count>0){
    			$this->success('留言修改成功','index');
    		}
    		else{
    			$this->error('留言修改失败');
    		}
    	}
        //search方法实现搜索
        public function search(){
            $where['content']=array('like',"%{$_POST['content']}%");

            $m=M('Bbs');
            $arr=$m->where($where)->select();
            $this->assign('data',$arr);
            $this->display('index');
        }
	}
?>