# AirFlow

Apache Airflow is an open-source workflow management platform. It started at Airbnb as a solution to manage the company's increasingly complex workflows.

Airflow is a platform created by the community to programmatically author, schedule and monitor workflows.

Use Airflow to author workflows as Directed Acyclic Graphs (DAGs) of tasks. The Airflow scheduler executes your tasks on an array of workers while following the specified dependencies. Rich command line utilities make performing complex surgeries on DAGs a snap. The rich user interface makes it easy to visualize pipelines running in production, monitor progress, and troubleshoot issues when needed.

When workflows are defined as code, they become more maintainable, versionable, testable, and collaborative.

## Principles

- Scalable : Airflow has a modular architecture and uses a message queue to orchestrate an arbitrary number of workers. Airflow is ready to scale to infinity.

- Dynamic : Airflow pipelines are configuration as code (Python), allowing for dynamic pipeline generation. This allows for writing code that instantiates pipelines dynamically.

- Extensible : Easily define your own operators, executors and extend the library so that it fits the level of abstraction that suits your environment.

- Elegant : Airflow pipelines are lean and explicit. Parametrizing your scripts is built into its core using the powerful Jinja templating engine.

## Features

1. Pure Python
2. Useful UI
3. Plenty of integrations : Airflow provides many plug-and-play operators that are ready to handle your task on Google Cloud Platform, Amazon Web Services, Microsoft Azure and many other services. This makes Airflow easy to use with your current infrastructure.

---

### Reference

https://en.wikipedia.org/wiki/Apache_Airflow

https://github.com/apache/airflow

https://airflow.apache.org/

https://issues.apache.org/jira/projects/AIRFLOW/issues/AIRFLOW-7120?filter=allopenissues
