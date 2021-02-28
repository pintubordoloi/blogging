function showBlogs(){
	document.querySelector('.content-pop').classList.remove("show")
	document.querySelector('.content-blogs').classList.toggle("show");
	

}

function showPop(){

	document.querySelector('.content-blogs').classList.remove("show")
	document.querySelector('.content-pop').classList.toggle("show");
}


//Subscibe popup box

let modal = document.querySelector('.sub-modal')
let subBtn = document.querySelector('.sub-btn');
let span = document.getElementsByClassName("close")[0];

subBtn.onclick = function(){
	modal.style.display = "block";
}

span.onclick = function(){
	modal.style.display = "none";
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
	} else if(e.target.matches('.sub-modal')){
		modal.display = "none";
	}
}


