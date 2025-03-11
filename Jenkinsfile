pipeline {
    agent {
        docker {
            image 'epitechcontent/epitest-docker'
        }
    }
    environment {
        githubName = "${env.GITHUB_USERNAME}"
    }
    options {
        githubProjectUrl("${env.GITHUB_USERNAME}")
    }
    triggers {
        scm('* * * * *')
    }
    stages {
        stage('Build') {
            steps {
                sh 'useradd student'
                sh 'cd $DEST_FOLDER'
                sh 'make fclean'
                sh 'make'
                sh 'make tests_run'
                sh 'make clean'
            }
        }
    }
}