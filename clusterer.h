#ifndef CLUSTERER_H
#define CLUSTERER_H
#include <string>
#include <vector>

namespace PLLKIA010
{
    class KMeansClusterer
    {   
        private: 
            std::string dataset;
            std::string output ;
            int bin;
            int k;
            bool color;
            bool hsv;
            int iterations;
            std::vector<std::vector<int>> features;
            std::vector<std::string> files;
            std::vector<std::string> classification;
        public: 
            KMeansClusterer(const std::string dataset, const std::string output, const int bins, const int clusters, const bool color, const bool hsv);
            ~KMeansClusterer(void);
            void generate(void);
            void generateFeatures(void);
            void generateRGBFeatures(void);
            void generateHSVFeatures(void);
            std::string cluster(void);
            std::string clusterHSV(void);
            std::vector<std::vector<int>> & getFeatures(void);
            double featureMean(const std::vector<int> &feature);
            double RGBMean(const double r, const double g, const double b);
            double HSVMean(const double h, const double s, const double v);
            int assignCluster(const std::vector<int> &feature, const std::vector<std::vector<int>> &means);
            int assignRGBCluster(const std::vector<int> &rfeature, const std::vector<int> &gfeature, const std::vector<int> &bfeature, const std::vector<double> &means);
            int assignHSVCluster(const std::vector<int> &hfeature, const std::vector<int> &sfeature, const std::vector<int> &vfeature, const std::vector<std::vector<int>> &means);
            double distance(const int featureMean, int mean);
            double euclideanDistance(const std::vector<int> &feature, const std::vector<int> &mean);
            double similarity(const std::vector<std::vector<int>> feature, const std::vector<std::vector<int>> mean);
            bool simpleConvergence(const std::vector<double> &means, const std::vector<double> &centroids);
            bool convergence(const std::vector<std::vector<int>> &means, const std::vector<std::vector<int>> &centroids);
            friend std::ostream& operator<<(std::ostream& os, const KMeansClusterer& kt);
    };
    std::ostream& operator<<(std::ostream& os, const KMeansClusterer& kt);  
}

#endif