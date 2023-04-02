#include<stdlib.h>
#include<QtWidgets>
#include<iostream>

class LoginWidget : public QWidget {
public:
    LoginWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(300, 150);
        setWindowTitle("Login");

        auto usernameLabel = new QLabel("Username:");
        auto passwordLabel = new QLabel("Password:");
        usernameEdit = new QLineEdit;
        passwordEdit = new QLineEdit;
        passwordEdit->setEchoMode(QLineEdit::Password);
        auto loginButton = new QPushButton("Login");
        auto quitButton = new QPushButton("Quit");

        auto layout = new QGridLayout;
        layout->addWidget(usernameLabel, 0, 0);
        layout->addWidget(usernameEdit, 0, 1);
        layout->addWidget(passwordLabel, 1, 0);
        layout->addWidget(passwordEdit, 1, 1);
        layout->addWidget(loginButton, 2, 0);
        layout->addWidget(quitButton, 2, 1);
        setLayout(layout);

        connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
        connect(loginButton, &QPushButton::clicked, this, &LoginWidget::attemptLogin);
    }

private slots:
    void attemptLogin() {
        auto username = usernameEdit->text();
        auto password = passwordEdit->text();
        if (username == "admin" && password == "password") {
            QMessageBox::information(this, "Login Successful", "You have successfully logged in.");
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
        }
    }

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    LoginWidget loginWidget;
    loginWidget.show();

    return app.exec();
}
