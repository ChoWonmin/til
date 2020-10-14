# Spark

>  Spark is a unified analytics engine for large-scale data processing. It provides high-level APIs in Scala, Java, Python, and R, and an optimized engine that supports general computation graphs for data analysis. It also supports a rich set of higher-level tools including Spark SQL for SQL and DataFrames, MLlib for machine learning, GraphX for graph processing, and Structured Streaming for stream processing.

> Apache Spark is a lightning fast real-time processing framework. It does in-memory computations to analyze data in real-time. It came into picture as Apache Hadoop MapReduce was performing batch processing only and lacked a real-time processing feature. Hence, Apache Spark was introduced as it can perform stream processing in real-time and can also take care of batch processing.

## Architecture

- 스파크는 사용 가능한 자원을 파악하기 위해 클러스터 매니저를 사용
- 드라이버 프로세스는 명령을 익스큐터에서 실행해야한다

1. 클러스터 매니저에게 스파크 어플리케이션 제출
2. Driver
    - 스파크 어플리케이션의 관련 정보 유지 관리
    - 사용자 프로그램/입력에 대한 응답
    - 전박적인 Executor의 작업 분석
    - 배포 스케줄링
    - 클러스터 노드 중 한 곳에서 실행
    - main() 실행
    - SparkSession
    - Spark API로 사용 가능
3. Executor
    - 드라이버 프로세스가 할당한 작업 수행
    - 진행 상황을 드라이버 노드에게 보고
    - spark code로 사용
4. API
    - 구조적 API
    - 비구조적/저수준 API

---

### Reference

https://spark.apache.org/

https://www.tutorialspoint.com/pyspark/index.htm
