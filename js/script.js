function showBlogs(){
	document.querySelector('.content-pop').classList.remove("show")
	document.querySelector('.content-blogs').classList.toggle("show");
	

}

function showPop(){

	document.querySelector('.content-blogs').classList.remove("show")
	document.querySelector('.content-pop').classList.toggle("show");
	


}
window.onclick = function(e){
	if(!e.target.matches('.dropbtn')){
		var dropBlog = document.querySelector('.content-blogs');
		var dropPop = document.querySelector('.content-pop');
		if(dropPop.classList.contains('show')){
			dropPop.classList.remove('show');
		} else if( dropBlog.classList.contains('show')){
			dropBlog.classList.remove('show');
		}
	}
}