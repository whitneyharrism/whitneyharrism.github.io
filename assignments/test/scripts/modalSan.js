

// Get the image and insert it inside the modal - use its "alt" text as a caption
var trigger = document.getElementById('myImg4');
var modal = document.querySelector(".modal4");
var closeButton = document.querySelector(".close-button4");

function toggleModal() {
    modal.classList.toggle("show-modal");
}

function windowOnClick(event) {
    if (event.target === modal) {
        toggleModal();
    }
}

trigger.addEventListener("click", toggleModal);
closeButton.addEventListener("click", toggleModal);
window.addEventListener("click", windowOnClick);