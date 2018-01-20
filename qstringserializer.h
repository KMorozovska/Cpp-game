#ifndef QSTRINGSERIALIZER_H
#define QSTRINGSERIALIZER_H

#include <QString>

namespace boost {
    namespace serialization {

        template<class Archive>
        void save( Archive & ar, const QString& qStringParam, const unsigned int )
        {
            // save class member variables
            std::string stdString = qStringParam.toStdString();
            ar & BOOST_SERIALIZATION_NVP(stdString);
        }

        template<class Archive>
        void load( Archive & ar, QString& qStringParam, const unsigned int )
        {
            // load class member variables
            std::string stdString;
            ar & BOOST_SERIALIZATION_NVP(stdString);
            qStringParam = qStringParam.fromStdString(stdString);
        }

        template<class Archive>
        void serialize(Archive & ar, QString & t, const unsigned int file_version)
        {
            split_free(ar, t, file_version);
        }

    } // namespace serialization
} // namespace boost
#endif // QSTRINGSERIALIZER_H
