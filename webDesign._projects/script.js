const form = document.getElementById('signup');
const nameInput = document.getElementById('name');
const emailInput = document.getElementById('email');
const passwordInput = document.getElementById('password');
const confirmInput = document.getElementById('confirm');

// Show or clear an error under a field
function setError(input, message) {
  const error = input.parentElement.querySelector('.error');
  error.textContent = message;
  input.classList.toggle('invalid', message !== '');
  input.classList.toggle('valid', message === '');
}

function validateName() {
  const ok = nameInput.value.trim().length >= 2;
  setError(nameInput, ok ? '' : 'Name must be at least 2 characters.');
  return ok;
}

function validateEmail() {
  const ok = /^\S+@\S+\.\S+$/.test(emailInput.value);
  setError(emailInput, ok ? '' : 'Enter a valid email address.');
  return ok;
}

function validatePassword() {
  const ok = passwordInput.value.length >= 8;
  setError(passwordInput, ok ? '' : 'Password must be at least 8 characters.');
  return ok;
}

function validateConfirm() {
  const ok = confirmInput.value !== '' && confirmInput.value === passwordInput.value;
  setError(confirmInput, ok ? '' : 'Passwords do not match.');
  return ok;
}

// Check each field when the user leaves it
nameInput.addEventListener('blur', validateName);
emailInput.addEventListener('blur', validateEmail);
passwordInput.addEventListener('blur', validatePassword);
confirmInput.addEventListener('blur', validateConfirm);

// Check everything when the form is submitted
form.addEventListener('submit', (e) => {
  e.preventDefault(); // stop the page from reloading

  const allValid = [
    validateName(),
    validateEmail(),
    validatePassword(),
    validateConfirm()
  ].every(Boolean);

  if (allValid) {
    alert('Registered successfully!');
    form.reset();
  }
});