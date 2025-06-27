# Signup and Login Test System in C

A simple and testable C-based project that simulates **user signup validation** and **login verification**, using file-based input and output.

---


## Project Structure

| File               | Description                                      |
|--------------------|--------------------------------------------------|
| `signup_test.c`    | Validates signup fields for multiple test cases  |
| `login_test.c`     | Verifies login credentials using file lookup     |
| `users.txt`        | Input data file (each line = one signup test)    |
| `results.txt`      | Output of signup test results (auto-generated)   |
| `.gitignore`       | Ignores compiled `.exe` and `.o` files           |

---


## How to Compile and Run (Windows CMD)

### Signup Validation

```bash
cd path\to\signup-page-c
gcc signup_test.c -o signup_test.exe
signup_test.exe
```
> Output will be saved in `results.txt`.

### Login Test

```bash
gcc login_test.c -o login_test.exe
login_test.exe
```
> Enter the **username** and **password** as prompted. If the credentials match `users.txt`, login succeeds.

### Sample users.txt Format

Each line must follow this format:
```ngnix
username email password confirm_password mobile
```

Example:
```graphql
sudha sudha@gmail.com Pass@123 Pass@123 9876543210
jaya jaya.com pass123 pass123 98abc32100
```
### Validation Rules
- Username: Minimum 3 characters
- Email: Must contain `@` and `.`
- Password: At least 6 characters, 1 uppercase, 1 lowercase, 1 digit, 1 symbol
- Confirm Password: Must match Password
- Mobile: Must be exactly 10 digits, numeric


## Output Example (`results.txt`)

```diff
Test Case 1:
-> Signup: PASS ✅

Test Case 2:
- Invalid Email
- Invalid Password
-> Signup: FAIL ❌
```

> To test login manually:
```bash
gcc login_test.c -o login_test.exe
login_test.exe
```
 > It will ask:
```yaml
Enter username:
Enter password:
```

If it matches a record in users.txt, it will print:
 - Login Successful!
 - Login Failed!

Sample users.txt Example
- Make sure your users.txt looks like this (5 space-separated fields):
  ```graphql
    sudha sudha@gmail.com Pass@123 Pass@123 9876543210
    jaya jaya.com pass123 pass123 98abc32100
  ```
![manual-login](https://github.com/user-attachments/assets/d4c0edda-f77b-4d56-911a-c85180ee3d43)

---

##  How to Add It to GitHub

1. Open your local `README.md` file
2. Replace its content with the above
3. Save the file

---

### Then Push to GitHub:

```bash
git add README.md
git commit -m "Updated README with project instructions"
git push
```

